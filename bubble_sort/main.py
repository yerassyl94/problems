def bubble_sort_list(_list: list):
	length = len(_list) - 1
	
	for x in range(length):
		for y in range(length-x):
			if _list[y] > _list[y+1]:
				_list[y],_list[y+1]=_list[y+1],_list[y]
	return _list

list_=[32,5,3,6,7,54,87]
print(bubble_sort_list(list_))
