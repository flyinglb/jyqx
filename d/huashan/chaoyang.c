// chaoyang.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ǻ�ɽ�Ķ��壬Ҳ�Ƴ����壬�ǻ�ɽ���ճ��ľ��Ѵ���춴˸�
��ƺ����Զ������������С�·屳��ɽ�ӡ�С�·�����һСͤ������
���ߣ�ͤ����������һ�֣��Ǿ��ǻ�ɽ�����ġ���̨���ˡ����������ϣ�
����һ��������ӡ���ഫΪ��������项��ɽʱ�����µģ����ʫ�С���
����������ɽ���鲨�����䶫��������ָ����ϹŴ�˵��
LONG );
        set("exits", ([ /* sizeof() == 1 */
           "westdown" : __DIR__"chaopath2",
        ]));
        set("objects", ([
            CLASS_D("huashan")+"/gao-laozhe": 1,
            CLASS_D("huashan")+"/ai-laozhe": 1,
        ]));

//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
