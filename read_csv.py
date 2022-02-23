from tokenize import group
import pandas as pd


def fun(seq):
    out = []
    count = 0
    for index in range(1, len(seq)):
        if seq[index] - seq[index - 1] != 1:
            count += seq[index] - seq[index - 1]
        else:
            out.append(count)
            count = 0
    cleaned = [num for num in out if num != 0]
    if not cleaned:
        return 0, 0
    max_out = max(cleaned)
    min_out = min(cleaned)
    return max_out, min_out


with open("log.csv", "r") as file:
    line = file.readline()
    packets_expected = int(line.split(',')[-1])


headers = ['hostname', 'port', 'sequence']
df = pd.read_csv('log.csv', names=headers, skiprows=1)
lists = df.groupby(["hostname", "port"])['hostname'].count()
grouped = df.groupby(["hostname", "port"])
keys = grouped.groups.keys()

results = {name: [i for i in range(packets_expected) if i not in df.loc[df['hostname'] == name, "sequence"].values]
           for name in df['hostname'].unique()}

for name, sequences in results.items():
    print(f"Hostname: {name}, Missing Sequences: {sequences}")

for i in keys:
    group = grouped.get_group(i)
    group.reset_index(drop=True, inplace=True)
    print(
        f"Hostname: {group['hostname'][0]} Max Missing/Out of Order Sequences: {fun(list(group['sequence']))[0]}")
    print(
        f"Hostname: {group['hostname'][0]} Min Missing/Out of Order Sequences: {fun(list(group['sequence']))[1]}")
    print(
        f"Hostname: {group['hostname'][0]} Ratio of Missing Packets:{group['hostname'].count() / packets_expected}")
