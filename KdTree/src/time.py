import subprocess
import time
import matplotlib.pyplot as plt
import numpy as np

NUMBER_OF_RUNS = 10
PREFERENCES_START = 10
PREFERENCES_END = 3000
PREFERENCES_STEP = 50

cpp_source_file = "main.cpp"
cpp_executable = "a" 
data = {}

for preferences in range(PREFERENCES_START, PREFERENCES_END + 1, PREFERENCES_STEP):
    compile_command = f"g++ -D NUMBER_OF_PREFERENCES={preferences} {cpp_source_file} GaleShapely.cpp -o {cpp_executable}.out"
    subprocess.run(compile_command, shell=True)

    preferences_times = []
    for _ in range(NUMBER_OF_RUNS):
        start_time = time.time()
        subprocess.run(["./"+cpp_executable+".out"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        end_time = time.time()
        elapsed_time = end_time - start_time
        preferences_times.append(elapsed_time)
    average_time = np.mean(preferences_times)
    std_dev = np.std(preferences_times)
    print(f"Average time for {preferences} preferences: {average_time} seconds, Standard deviation: {std_dev} seconds")

    data[preferences] = {'average': average_time, 'std_dev': std_dev}


preferences_values = [key for key in data.keys()]
average_times = [data[key]['average'] for key in preferences_values]
std_devs = [data[key]['std_dev'] for key in preferences_values]


plt.errorbar(preferences_values, average_times, yerr=std_devs, fmt='o-', color='b', ecolor='r', capsize=4)
plt.xlabel('Number of Preferences')
plt.ylabel('Average Time (seconds)')
plt.title(f'Average Execution Time with Standard Deviation for Different Numbers of Preferences')
plt.show()
