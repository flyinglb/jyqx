// shulin7.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ܸС��������ϡ�
�Ͷ�����һ��С����
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "south"    : __DIR__"shenheyuan",
                "northup"  : __DIR__"juyan",
                "eastdown" : __DIR__"heifengdong",
        ]));

        setup();
        replace_program(ROOM);
}
