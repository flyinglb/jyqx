//m_weapon .....tianjianshi.c

inherit ROOM;

void create()
{
	set("short", "ɳĮ����");
	set("long",
	     "������ɳĮ�в����һ�����ޣ����ϲ�Զ��Լ���Կ���һ���ںڵ�ɽ������紫��һЩ\n"
	     "���������Ĵ�����������Ҳ��֪��˭�ڴ���ʲô��\n"

	);
	set("exits", ([
		"east" : "/d/xingxiu/nanjiang2",
		"south" : __DIR__"xuanbing",
	]));
	setup();
	replace_program(ROOM);
}
