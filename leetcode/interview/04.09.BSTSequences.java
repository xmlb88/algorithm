ArrayList<LinkedList<Integer>> allSequences(TreeNode node) {
2 ArrayList<LinkedList<Integer>> result = new ArrayList<LinkedList<Integer>>();
34
if (node == null) {
5 result.add(new LinkedList<Integer>());
6 return result;
7 }
89
LinkedList<Integer> prefix = new LinkedList<Integer>();
10 prefix.add(node.data);
11
12 /* �����������ݹ� */
13 ArrayList<LinkedList<Integer>> leftSeq = allSequences(node.left);
14 ArrayList<LinkedList<Integer>> rightSeq = allSequences(node.right);
15
16 /* ��ÿ��������������˽������ */
17 for (LinkedList<Integer> left : leftSeq) {
18 for (LinkedList<Integer> right : rightSeq) {
19 ArrayList<LinkedList<Integer>> weaved =
20 new ArrayList<LinkedList<Integer>>();
21 weaveLists(left, right, weaved, prefix);
22 result.addAll(weaved);
23 }
24 }
25 return result;
26 }
27
28 /* �����п��ܵķ�ʽ������ͬʱ������㡣���㷨��һ�������ͷ���Ƴ�Ԫ�أ��ݹ飬
29 * ������һ����������ͬ�Ĳ��� */
30 void weaveLists(LinkedList<Integer> first, LinkedList<Integer> second,
31 ArrayList<LinkedList<Integer>> results, LinkedList<Integer> prefix) {
32 /* һ�������ѿա���ʣ�ಿ�ּ��뵽�����ƺ�ģ� prefix �в��洢��� */
33 if (first.size() == 0 || second.size() == 0) {
34 LinkedList<Integer> result = (LinkedList<Integer>) prefix.clone();
35 result.addAll(first);
36 result.addAll(second);
37 results.add(result);
38 return;
39 }
40
41 /* �� first ��ͷ�����뵽 prefix ����еݹ顣�Ƴ�ͷ��Ԫ�ػ��ƻ� first��
42 * ���������Ҫ�ں�������ʱ��Ԫ�طŻ� */
43 int headFirst = first.removeFirst();
44 prefix.addLast(headFirst);
45 weaveLists(first, second, results, prefix);
46 prefix.removeLast();
47 first.addFirst(headFirst);
48
49 /* �� second ����ͬ�������ƻ������ָ� */
50 int headSecond = second.removeFirst();
51 prefix.addLast(headSecond);
52 weaveLists(first, second, results, prefix);
53 prefix.removeLast();
54 second.addFirst(headSecond);
55 }