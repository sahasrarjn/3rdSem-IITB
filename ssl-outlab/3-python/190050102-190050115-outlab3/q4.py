class Node(object):
	"""
	Node contains two objects - a left and a right child, both may be a Node or both None,
	latter representing a leaf
	"""
	def __init__(self, left=None, right=None):
		super(Node, self).__init__()
		self.left = left
		self.right = right

	def __str__(self):
		"""
		Default inorder print
		"""
		if self.left is None and self.right is None:
			return "(   )"
		else:
			return "( " + str(self.left) + " " + str(self.right) + " )"

	def __eq__(self, other):
		if self.left is None and self.right is None:
			return other.left is None and other.right is None
		elif other.left is None and other.right is None:
			return False
		else:
			return self.left == other.left and self.right == other.right


def mirrorTree(node):
	temp = Node()
	if node.left is not None:
		temp.right = mirrorTree(node.left)
	if node.right is not None:
		temp.left = mirrorTree(node.right)

	return temp
	pass


def allTrees(n):
	trees =[]
	if n == 0 :
		temp = Node()
		return [temp]
	else:
		for l in range(0,n):
			r = n-1-l
			ltrees = allTrees(l)
			rtrees = allTrees(r)
			trees += [Node(newl,newr) for newl in ltrees for newr in rtrees]
	return trees
	pass


def allSymTrees(n):
	sym = []
	if(n == 0) :
		return [Node()]
	if(n%2 == 0):
		return sym
	total = allTrees((n-1)//2)
	sym = [Node(tree,mirrorTree(tree)) for tree in total]
	return sym
	pass


if __name__ == '__main__':
	for x in allSymTrees(int(input())):
		print(x)
	node = Node(Node(Node(), Node()), Node())
	print(node)