// Room: liubeidian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���������������������й��ź����ҵۣ��߿���������ȴû��
�����ν "��������" �İ����ɡ�����������ı��������ȵ��ܺ�Ӣ��
ͬ�룬���˲�ʤ���ꡣ
    �������������Ƶȵ��佫�Ⱥͽ���Ϊ�׵��ĳ��ȡ�
LONG );
	set("exits", ([
		"south"   : __DIR__"wuhoucigate",
		"northup" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
