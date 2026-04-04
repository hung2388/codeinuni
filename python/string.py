name=input("what is your name: ")
print(len(name))
print(name.find("t")) #in ra vị trí đầu tiên co schuwx t
print(name.capitalize()) #viết hoa chữ đầu tiên, đưa toàn bộ còn lại thành chữ thường
print(name.upper())# viết hoa cả cụm
print(name.lower())# tắt hoa cả cụm
print(name.isdigit()) #có phải số k
print(name.isalpha())
print(name.count("-"))
print(name.replace("-"," "))
print(f"welcom {name}")