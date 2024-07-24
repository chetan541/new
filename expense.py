import sqlite3
from datetime import datetime

class Expense:
    def __init__(self, date, amount, category, description):
        self.date = date
        self.amount = amount
        self.category = category
        self.description = description

    def get_amount(self):
        return self.amount

    def get_category(self):
        return self.category

    def get_description(self):
        return self.description

    def get_date(self):
        return self.date

class ExpenseTrackerApp:
    def __init__(self, username):
        self.username = username
        self.conn = sqlite3.connect('expense_tracker.db')
        self.create_tables()

    def create_tables(self):
        cursor = self.conn.cursor()
        cursor.execute('''
            CREATE TABLE IF NOT EXISTS expenses (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                username TEXT,
                date TEXT,
                amount REAL,
                category TEXT,
                description TEXT
            )
        ''')
        self.conn.commit()

    def add_expense(self, expense):
        cursor = self.conn.cursor()
        cursor.execute('''
            INSERT INTO expenses (username, date, amount, category, description)
            VALUES (?, ?, ?, ?, ?)
        ''', (self.username, expense.get_date(), expense.get_amount(), expense.get_category(), expense.get_description()))
        self.conn.commit()

    def get_expenses(self):
        cursor = self.conn.cursor()
        cursor.execute('''
            SELECT date, amount, category, description FROM expenses WHERE username = ?
        ''', (self.username,))
        return cursor.fetchall()

    def calculate_total_expense(self):
        cursor = self.conn.cursor()
        cursor.execute('''
            SELECT SUM(amount) FROM expenses WHERE username = ?
        ''', (self.username,))
        total = cursor.fetchone()[0]
        return total if total else 0

# Example Usage
if __name__ == "__main__":
    username = input("Enter your username: ")
    expense_tracker = ExpenseTrackerApp(username)

    while True:
        print("\nExpense Tracker Menu:")
        print("1. Add Expense")
        print("2. View Expenses")
        print("3. View Total Expenses")
        print("4. Exit")

        choice = input("Enter your choice (1/2/3/4): ")

        if choice == '1':
            date = input("Enter date (YYYY-MM-DD): ")
            amount = float(input("Enter amount: "))
            category = input("Enter category: ")
            description = input("Enter description: ")

            expense = Expense(date, amount, category, description)
            expense_tracker.add_expense(expense)
            print("Expense added successfully!")

        elif choice == '2':
            expenses = expense_tracker.get_expenses()
            if not expenses:
                print("No expenses found.")
            else:
                print("\nList of Expenses:")
                for expense in expenses:
                    print(f"Date: {expense[0]}, Amount: {expense[1]}, Category: {expense[2]}, Description: {expense[3]}")

        elif choice == '3':
            total_expense = expense_tracker.calculate_total_expense()
            print(f"\nTotal Expenses: {total_expense}")

        elif choice == '4':
            print("Exiting Expense Tracker. Goodbye!")
            break

        else:
            print("Invalid choice. Please enter a valid option.")
