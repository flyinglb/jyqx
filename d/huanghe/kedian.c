// kedian.c
// Java Sep. 21 1998

inherit ROOM;

void create()
{
        set("short", "�͵�");
        set("long", @LONG
����һ�ҵ��ؾ��񿪵ļ�ëС�꣬¥����Щ±�˺��Ӿƣ�¥������
�ͷ��������ڽ�����ɽ��ǰ��Ψһ��Ϣ֮�����������䣬��ҩ�͵Ƚ���
��������ʱ���ɿ���һ����Ѱ�ɷõ�֮����ǽ����һ������(paizi)��
������һ����ǡ�
LONG);
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                "/d/hangzhou/npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"majiu",
                "east" : __DIR__"yongdeng",
                "up"   : __DIR__"kedian2",
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "up" )
     return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס���ס
���˻���ΪС���ź����أ�\n");

        return ::valid_leave(me, dir);
}

