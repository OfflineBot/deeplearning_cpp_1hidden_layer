import numpy as np

list1 = [
    [1.0, 2.0],
    [3.0, 4.0],
    [5.0, 6.0],
]

list2 = [
    [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0],
    [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0],
]

final = [
    [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
]

print(f"({len(list1)}, {len(list1[0])})")
print(f"({len(list2)}, {len(list2[0])})")
print(f"({len(final)}, {len(final[0])})")

rows1 = len(list1)
cols1 = len(list1[0])
rows2 = len(list2)
cols2 = len(list2[0])

for row1 in range(0, rows1):
    for col1 in range(0, cols1):
        print(list1[row1][col1]) 
    
        for col2 in range(0, cols2):
            final[row1][col2] += list1[row1][col1] * list2[col1][col2]


print("-- -- --")
for i in range(0, 3):
    print(final[i])


input_test = np.array(list1)
output_test = np.array(list2)
print(np.dot(input_test, output_test))