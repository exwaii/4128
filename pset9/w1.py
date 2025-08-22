with open("0102_triangles.txt", "r", encoding="utf-8") as f:
    a = f.readlines()
    for line in a:
        line = line.split(",")
        line = list(map(int, line))
        