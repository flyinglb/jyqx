//LUCAS 2000-6-18
// Room: sroad1.c

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
�����￪ʼ�������������ǵ�ɽ·�ˡ�̧ͷһ����ѩ��߲�
�����������������Լ�վ��֮������������ɽ�Ÿ�һ�㣬ȴ����
�㡰�ߴ���ʤ����֮���ˡ�һ·�������仹��ɽ�ţ�ȴ�Ѹо���
�������ˣ�·�Ե����ϣ�ȫ�����˰�ѩ���裬һ����紵������
������ͷ���֡�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "eastdown"  : __DIR__"boot",
            "northup"  : __DIR__"sroad2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

