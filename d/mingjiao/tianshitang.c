//tianweitang.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��һ�������̵������ã���ʱ�е�һ����ɱ֮�������ڳ��붼ʮ��
С�ģ�Ω�־�����������ľ�������������ԫ�������������ԫ̧�ۿ�
�˿��㣬һ�ź���͵���ȴ���������ľ�������
LONG );
        set("exits", ([
                "west"  : __DIR__"tianweitang",
        ]));
        set("objects",([
             __DIR__"npc/litianyuan":1,
             __DIR__"npc/yinwulu":1,
        ]));
        setup();
        replace_program(ROOM);
}
