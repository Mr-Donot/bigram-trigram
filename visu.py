from matplotlib import pyplot as plt

content = []
with open("stat.txt", "r") as f:
    for line in f.readlines():
        if line != "\n" : content.append(float(line.replace("\n", "")))

nb_words = []
seq_time = []
par_time = []

for i in range(len(content)):
    if i % 3 == 0:
        nb_words.append(content[i])
    elif i % 3 == 1:
        seq_time.append(content[i])
    else:
        par_time.append(content[i])



#We reduce the time to a better fit for the plotting
seq_time = list(map(lambda x : x / 1000_000_000, seq_time))
par_time = list(map(lambda x : x / 1000_000_000, par_time))


plt.plot(nb_words, seq_time, color="red", marker="o")
plt.plot(nb_words, par_time, color="blue", marker="s")

plt.show()

print(nb_words)
print(seq_time)
print(par_time)