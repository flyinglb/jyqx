// shulin0.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬
�������������һȺ���ɫ���۷��������Է�����ȥ��ֻ��һ��ʯ
��(shibei)���ڵ��ۨ洦��������һ��յء�����������ï�ܵ���
�֡�
LONG
        );
        set("outdoors", "gumu");
        set("item_desc", ([
                "shibei" : 
"

                        ���Ϲ�Ĺ��
                        ����ֹ����

",
        ]));
        set("exits", ([
                "southup" : __DIR__"shulin1",
                "north" : __DIR__"shulin4",
                "west"  : __DIR__"shulin5",
                "east"  : __DIR__"shulin6",
        ]));

        setup();
        replace_program(ROOM);
}
