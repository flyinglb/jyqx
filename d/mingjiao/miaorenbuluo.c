//miaorenbuluo.c

inherit ROOM;

void create()
{
        set("short", "���˲���");
        set("long", @TEXT
����ǰͻȻһ����ԭ�����߽���һ�����˲��䡣������Χ���ڻ�
�ѱߣ���ɫ�ϣ���������ĳ�ּ�����ʽ��������ʿ������ľ�ۣ���\
�������дʡ�ͻȻ�����Ǻ��������㡣
TEXT );
 	set("exits",([
	      "north" : __DIR__"westroad2",
	]));
	set("objects",([
		"/d/mingjiao/npc/miaozuwushi":4,	
	]));
	setup();
	replace_program(ROOM);
}
