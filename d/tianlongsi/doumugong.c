inherit ROOM;

void create()
{
        set("short", "��ĸ��");
        set("long",@LONG
���Ǹ����������Ϣ�ĵط�������Χ����һ��̴ľ�����Ρ���������
������������Ϣ��
LONG );
        set("exits", ([
                "southwest" : __DIR__"doushuai",
		"north" : __DIR__"yuhuayuan",
	]));
	set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
