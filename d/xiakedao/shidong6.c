// /d/xiakedao/shidong6.c ���͵� ʯ��

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ����������խ���������˲������������Ҳ���ǵ�
�������ֱ�ɴ������͵ƻζ��������������������Ӱ���Ų����
ʯ���˶���������������о���Щ������
LONG );
        set("exits", ([
                "south" : __DIR__"shidong7",
                "north" : __DIR__"shidong1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
