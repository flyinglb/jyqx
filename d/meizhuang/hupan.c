// hupan.c
inherit ROOM;

void create()
{
        set("short", "�Ϻ�����");
        set("long", @LONG
˳���Ϻ�һֱ�߹�ȥ���������ź��ߵ���������֪�������Ѿ���
���Ϻ��ľ�ͷ��������һ�����ѵ�С·��ǰ�����ţ�����ԼԼ���Կ�
��һ��ׯ԰���㲻�����߹�ȥ����������ʲô�ط���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/quanzhou/nanhu1",
  "north" : __DIR__"xiaolu.c",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

