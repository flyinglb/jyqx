// walle2.c

inherit ROOM;

void create()
{
        set("short", "��ͷ");
        set("long", @LONG 
ѩ��ƮƮ��վ�������֮�����������֮���ơ���˼������
�ʣ�Ϊ����ͼ��ҵ��ÿÿ����Զ������ɽ��������ȴ������ս
������ɽ���죬ƫ�����˷صء�����˾���������������������
�ԣ��������޶��ӱ߹ǣ����Ǵ��������ˡ���Ϊһ��֮��������
��֮�ˣ��Ž�ͬ�ӣ�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "east"   : __DIR__"walle3",
                "west" : __DIR__"walle1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 
        setup();
        replace_program(ROOM);
}

