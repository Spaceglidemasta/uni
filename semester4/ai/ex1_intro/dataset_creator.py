import csv
import random


num_rows = 100000

with open("age_income_years_worked.csv", "w", newline="", encoding="utf-8") as csvfile:
    writer = csv.writer(csvfile, delimiter=",")
    # Header
    writer.writerow(["Age", "Income", "YearsWorked","Credible"])

    for row in range(num_rows):
        age = random.randint(16, 65)

        # Income:  (age * 70) + Noise with Gauss-distribution
        income = int(age * 70 + random.gauss(0, 200))
        if income < 540:
            income = 540  # Mindest-Einkommen

        if income >= (age * 70):
            credible = 1
        else:
            credible = 0

        # Years worked: between 0 and (age - 16)

        years_worked = random.randint(0, age - 16)

        writer.writerow([age, income, years_worked, credible])

print("The file 'age_income_years_worked.csv' has been created.")