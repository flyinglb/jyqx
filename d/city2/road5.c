inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡����߾����������ˡ�
LONG );
        set("exits", ([
                "north" : "/d/city2/yongding",
                "west"  : "/d/xueshan/bieyuan",
                "east"  : __DIR__"yizhan",
                "southeast" : __DIR__"road6",
        ]));
        set("objects",([
                "/d/taishan/npc/seng-ren" : 1,
        ]));
        set("outdoors", "city2");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

