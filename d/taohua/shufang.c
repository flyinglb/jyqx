inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ��ɸɾ������鷿������һ����̴ľ�������Ϸ��Ų����鼮��
��ǽ�ĵط�����һ����ܣ�����������ȫ�Ǹ��ַ�װ���顣���в�����
����ȥ���ⰻȻ����Ȼ����Ѿá�
LONG );
	set("exits", ([
		"down" : __DIR__"daojufang",
	]));
	set("objects", ([
		"/clone/book/yijing"+random(4) : 1,
		"/clone/book/yijing"+random(4) : 1,
		"/clone/book/bagua"+random(2)  : 1,
		CLASS_D("taohua")+"/qu": 1,
	]) );
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
