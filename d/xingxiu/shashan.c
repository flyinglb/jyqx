// room: /d/xingxiu/shashan.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "��ɳɽ");
        set("long", @LONG
����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵�������
�ʶ������˳�֮Ϊ��ɳɽ��ɳ�����ƺ���һ�ֳ������䶯��
LONG );
        set("outdoors", "xingxiuhai");
//        set("no_clean_up", 0);
        set("exits", ([
                "west"      : __DIR__"yueerquan",
                "northeast" : __DIR__"silk3",
        ]));
        set("objects", ([
                __DIR__"npc/shachong" : 1
        ]));
        setup();
        replace_program(ROOM);
}

