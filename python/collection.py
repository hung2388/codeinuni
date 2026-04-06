fruits=["apple","banana","coconut","dragon fruit"]
print(fruits[1:3])
#print(dir(fruits)) #print những method của loại fruits
fruits.reverse();
print(fruits)
#print(help(fruits))
print(len(fruits))
print("apple" in fruits)
print("real" in fruits)
fruits.append("mango")
print(fruits)
fruits.remove("banana")
print(fruits)
fruits.insert(1,"appba")
fruits.sort()
print(fruits)
#fruits.clear() #xóa hết tất cả
print(fruits.index("appba"))
print(fruits.count("apple")) #đếm số lần apple xuất hiện