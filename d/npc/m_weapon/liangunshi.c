//ROOM liangunshi.c
inherit ROOM;

void create()
{
        set("short", "���");
        set("long",
		"�����������Ŷ�����ĵط�����Χ����Ķѷ�������õ�ԭ�ϣ�һ������\n"
		"С����������һ�����������������ϸ���ж��š����������˹�������æ����\n"
		"���е��飬����һ��������㺩����һЦ���������ֺ��ˡ�\n"
        );
        set("exits", ([
                "east" : "/d/xueshan/shenghu",
        ]));

	set("objects",([__DIR__"npc/shigun" : 1,]));

        setup();
	replace_program(ROOM);
}
