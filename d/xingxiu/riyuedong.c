// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���¶�");
        set("long", @LONG
�������������ܶ����ڵ����¶������ڵƻ�ͨ��������һ�ѻ�Ƥ���϶�����
�����������˶����������װ���Ż�Ƥ��¹ͷ�����𣬼�һЩ�ֻ�(zihua)��
���������������ܣ��������еĴ���Ǹ��ֹ�����
LONG );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "����Щ�����������ɵ�ʫ�ʺ����Ļ���\n

����������������������������������
����������������������������������
�����������š������¡��ǡ���������
���������������䡡�ޡ���������
�����������ޡ�御��졡�ϡ���������
�����������ȡ���ء��ɡ���������
����������������������������������
����������������������������������
"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiegun" : 1,
        ]) );
//        set("no_clean_up", 0);
//        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);

}
