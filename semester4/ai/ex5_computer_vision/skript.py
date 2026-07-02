

A = [
    [0, 2, 3, 0, 3],
    [4, 0, 8, 3, 0],
    [0, 7, 5, 0, 3],
    [8, 0, 5, 6, 2],
    [0, 0, 4, 2, 3]
]

h1 = [
    [2, 1, -1, -2],
    [2, 1, -1, -2],
    [2, 1, -1, -2],
    [2, 1, -1, -2]
]


def crossCorrelation2d(input, kernel):
    kernel_size = len(kernel)
    output_size = len(input) - kernel_size + 1
    output = [[0 for _ in range(output_size)] for _ in range(output_size)]

    for i in range(output_size):
        for j in range(output_size):
            outsum = 0
            for k in range(kernel_size):
                for l in range(kernel_size):
                    outsum += input[i + k][j + l] * kernel[k][l]
            output[i][j] = outsum

    return output

def convolution2d(input, kernel):
    kernel_size = len(kernel)
    output_size = len(input) - kernel_size + 1
    output = [[0 for _ in range(output_size)] for _ in range(output_size)]

    for i in range(output_size):
        for j in range(output_size):
            outsum = 0
            for k in range(kernel_size):
                for l in range(kernel_size):
                    outsum += input[i + k][j + l] * kernel[kernel_size - 1 - k][kernel_size - 1 - l]
            output[i][j] = outsum

    return output



for row in convolution2d(A, h1):
    print(row)



for row in crossCorrelation2d(A, h1):
    print(row)

