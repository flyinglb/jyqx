
inherit ROOM;

string look_writing();

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȡ�����һ��֧������ĸ�ǽ�ϣ���һ�����붫
�����͵��ݶ�����������������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�������ĵ��ƺ�������˵һ���渶��˵Ĺ��¡�
����ͨ����Ժ���ϱ����з��䡣
LONG );
	set("exits", ([
		"west" : __DIR__"houyuan",
		"east" : __DIR__"qihedian",
		"south" : __DIR__"fang1",
		"north" : __DIR__"fang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

