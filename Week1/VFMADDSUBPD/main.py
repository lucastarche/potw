words = {}

first_line = input().split()
iterations = int(first_line[0])
for i in range(int(first_line[1])):
    line = input().split()
    words[int(line[0])] = line[1]

for n in range(1, iterations+1):
    o = ""
    for i, word in words.items():
        if n % i == 0:
            o += word
    print(o if o else n)
