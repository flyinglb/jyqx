// path1.c

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
������ɽ��ΡȻ����������ʡ�����س��ϡ�����ƺӣ��������룬
����ɽ��ߵʹ��䣬����һ�����������һ������������ɽ������������
�жȣ�������ɣ�ԶԶ��ȥ��״���޶���������Χ��������꣬�м�����
��������ɽ����'��'������ȡ����ɽ�������������ٻ�ɽ���ʻ�ɽ��
��̫���������С�������µ�һɽ��֮�ƣ�������С�塣������ȪԺ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/village/eexit",
            "north" : __DIR__"yuquan",
            "southeast" : __DIR__"shaluo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
