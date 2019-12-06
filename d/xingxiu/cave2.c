//room: /d/xingxiu/cave2.c

inherit ROOM;

void init();
int do_lingwu(string);

void create()
{
	set("short","�޵׶�");
	set("long",@LONG
�����ƺ��Ǵ�˵�е��޵׶��������ںڵĿ���̫�������Լ���ܿ���
һ�㶴������һЩ�Źֵ�����ͼ��(tu)�����룬���������ǲ��ǿ�������
(lingwu)��ʲô�أ�
LONG );
	set("exits",([
		"out" : __DIR__"cave",
	]));
	set("item_desc",([
		"tiesuo" : "ͼ���Ͽ��źܶ�С�ˣ���������ʲô�ڻ��裬��֪���ܲ�������һ���书��\n" ,
	]));
	setup();
}

void init()
{
	add_action("do_lingwu","lingwu");
}

int do_lingwu(string arg)
{
	object ob;
	int c_skill;
	int exp;
	ob = this_player();
	exp=(int)ob->query("combat_exp");

	if (arg != "tu") return 0;
	c_skill=(int)ob->query_skill("blade", 1);

	if (ob->query("jing")<100)
		return notify_fail("��̫���ˣ��޷�����ʲô��\n");
	if (c_skill< 250)
		return notify_fail("����Ŷ�����ĥ�����ã��޷�����������ʲô��\n");
	if (exp*10 <= (c_skill*c_skill*c_skill)) {
		ob->receive_damage("jing", 50);
		return notify_fail("��ľ��鲻�����޷���������ʲô�ˡ�\n");
        }

	message_vision("$N�������ã���㱼��ƺ�������ʲô��\n",ob);
        ob->improve_skill("blade", random(50*ob->query("int")));
        ob->receive_damage("jing", 70);
        return 1;
}
