// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "�չ���");
        set("long", @LONG
����һ��С�չ���, ������������ë��̺�����ϰ�Ϊһ��˹��, ר����
�������������һ�Ŵ���Ƥֽ��,д�����չ��ĸ��������(sign)��
LONG
        );
        set("exits", ([
            "east" : __DIR__"huijiang3",
        ]));
        set("objects", ([
                __DIR__"npc/dealer": 1 ]) );
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "��Ƥֽ��д����
��ԭǮ��ͨ�á�
        ���ܹ�(hamigua)
        ��Ƥ(yangpi)
        ��Ƥ(langpi)
        ë̺(maotan)
        ѩ��(xuecan)
\n"
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
