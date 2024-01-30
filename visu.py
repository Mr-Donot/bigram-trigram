from matplotlib import pyplot as plt

content = []
with open("stat.txt", "r") as f:
    for line in f.readlines():
        if line != "\n" : content.append(float(line.replace("\n", "")))

nb_words = []
seq_time = []
par2_time = []
par4_time = []
par6_time = []
par8_time = []
nb_values = 6
for i in range(len(content)):
    if i % nb_values == 0:
        nb_words.append(content[i])
    elif i % nb_values == 1:
        seq_time.append(content[i])
    elif i % nb_values == 2:
        par2_time.append(content[i])
    elif i % nb_values == 3:
        par4_time.append(content[i])
    elif i % nb_values == 4:
        par6_time.append(content[i])
    elif i % nb_values == 5:
        par8_time.append(content[i])



#We reduce the time to a better fit for the plotting
print(seq_time)
print(par2_time)
print(par4_time)
print(par6_time)
print(par8_time)        

seq_time = list(map(lambda x: x / 1000_000_000, seq_time))
par2_time = list(map(lambda x: x / 1000_000_000, par2_time))
par4_time = list(map(lambda x: x / 1000_000_000, par4_time))
par6_time = list(map(lambda x: x / 1000_000_000, par6_time))
par8_time = list(map(lambda x: x / 1000_000_000, par8_time))

print(seq_time)
print(par2_time)
print(par4_time)
print(par6_time)
print(par8_time)
print(nb_words)

plt.style.use('seaborn-darkgrid')

plt.plot(nb_words, seq_time, color="red", marker="o", label="Sequential")
plt.plot(nb_words, par2_time, color="blue", marker="s", label="Parallel (2 Threads)")
plt.plot(nb_words, par4_time, color="green", marker="d", label="Parallel (4 Threads)")
plt.plot(nb_words, par6_time, color="yellow", marker="p", label="Parallel (6 Threads)")
plt.plot(nb_words, par8_time, color="purple", marker="*", label="Parallel (8 Threads)")

plt.xlabel("Number of Words", fontsize=12)
plt.ylabel("Execution Time (seconds)", fontsize=12)
plt.title('Sequential vs Parallel Execution Times', fontsize=14)

plt.legend(fontsize=10, shadow=True)

plt.grid(True, linestyle='--', alpha=0.7)
plt.show()
