// shimen.c ����


inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������������ͷ����ǰһ�����ص�ʯ�š����Ͽ������������
��׭���������С��������վã��Ǳʻ��İ���֮������������̦��Խ
���Եò�ɣ�������еľ�����Ȼ������
    ������һ���ʯ�ڣ���ʯ���º����кܶ��ˡ�
LONG );
        set("exits", ([
                "enter" : __DIR__"shibi",
                "north" : __DIR__"yongdao3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi3" : 1]));
        setup();
        replace_program(ROOM);
}
