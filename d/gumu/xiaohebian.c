// xiaohebian.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С�ӱ�");
        set("long", @LONG
�˴�λ�����ɽ��һƫƧ����ֻ��Ũ���ѵأ����⸡������Χ��
�������ľ���ľ��ľ�֮������Զ����С����ɽ��(dong)��ӿ����Ȫ
ˮ���γɣ����ȵ�ˮ���������������˳����������ͨ��ɽ�����
�����ɽ���ɽ���С�
LONG
        );
        set("outdoors", "gumu");
        set("item_desc", ([
                "dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong",
                "north" : __DIR__"shanlu16",
        ]));

        setup();
        replace_program(ROOM);
}
