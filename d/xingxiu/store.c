// room: /d/xingxiu/nanjiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ���ӻ��̡����������ŵ�̺�����ϰ����ڵ�̺�ϣ�
�Ա߶������Ļ���ǽ���и����ӣ��Ǹ���Ŀ��(sign)��
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"beijiang",
        ]));
        set("objects", ([
                __DIR__"npc/maimaiti": 1
        ]) );
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "������д����
��ԭǮ��ͨ�á�
        ���̾ƺ�(hu)       һ����
        ��(nang)           ��ʮ��
        ����(fire)         һ����
        ���ܹ�(gua)        ��ʮ��
        ������(dongbula)   һ����
        ������(horse)      һǧ�� ( ���� )
\n"
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

 
