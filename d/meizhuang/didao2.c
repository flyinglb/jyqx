// midao2.c
inherit ROOM;

void create()
{
        set("short", "÷ׯ�ܵ�");
        set("long", @LONG
����һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫������
��ѣ��ص����Ե�ǽ���ϻ��źܶ಻֪�����Ժ���֮�ֵıڻ�������
�����൱�ѿ�����ӿ�Ų�����֪���ص��ľ�ͷ��ʲô�ط��� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"didao1",
            "north" : __DIR__"didao6",
            "west" : __DIR__"didao2",
            "east" : __DIR__"didao1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

