// shijie.c
inherit ROOM;

void create()
{
        set("short", "��ɽʯ��");
        set("long", @LONG
�����ɽ�ߵ�ʯ������ȥ��һ·�����ź��߳�ҷ����������֪��
����ת�˼����䣬ȴ����ض���÷�����ϸɺ�б��֦Ҷï�ܣ������
��÷��ʢ��֮�գ���ѩ�纣����Ȼ���Ͳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "eastdown" : "/d/hangzhou/gushan",
            "north"    : __DIR__"xiaolu.c",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

