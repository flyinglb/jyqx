//ROOM lianchuishi.c
inherit ROOM;

void create()
{
        set("short", "��ƺ");
        set("long",
	"�����������Ŷ��Ĵ���ִ��ĵط������ڻ������̵Ĵ�ѩɽ�ϡ���ѩɽ����\n"
	"��ѩ������ȴ��һƺ���ݷ��ص�ɽ�ȡ����ܰ��˺ܶ�ͭ�����һ������������\n"
	"ִ�󴸣��������߽�������\n"
        );
        set("exits", ([
                "eastdown" : "/d/xuedao/nroad5",
        ]));

	set("objects",([__DIR__"npc/shichui" :1,]));

        setup();
	replace_program(ROOM);
}
