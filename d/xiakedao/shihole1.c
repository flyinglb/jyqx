// /d/xiakedao/shihole1.c ���͵� ʯ��1

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������������ʯ��������ͨ���ľ�ʫ��ʯ�ҡ�������ϰ������
�С��书����������ܸ٣�Ҳ�ֱ��������˶�һɫ�಼�ᣣ���
���ĵ��Ӿ������³�����������ϣ���������ǰ�ľ�ʫ���ܸ١�һ��
�ɺ衹��
LONG );
        set("exits", ([
                "out"   : __DIR__"neiting",
                "enter" : __DIR__"shihole2",
                "north" : __DIR__"shiroom01",
                "south" : __DIR__"shiroom02",
                "east"  : __DIR__"shiroom03",
                "west"  : __DIR__"shiroom04",
        ]));
        set("objects", ([
                __DIR__"npc/wangwu": 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object *inv;
        me = this_player();
        if(dir!="out")
        {
           if( me->query("weiwang")>=20 )
           {
                inv = all_inventory(me);
                for(i=sizeof(inv)-1; i>=0; i--)
                   if(inv[i]->query("weapon_prop") && ((string)inv[i]->query("equipped")=="wielded"))
                       if(objectp(present("wang", environment(me))) &&
                           living(present("wang", environment(me))))
                         return notify_fail("������ǰ��ס�㣬����˵������λ" +
                             RANK_D->query_respect(me) + "�����Ǳ����صأ���׼�����书������Խ�ȥ���������ֱֳ��С�\n");
                return ::valid_leave(me, dir);
           }
           else
           {
                   if(objectp(present("wang wu", environment(me)))&&
                   living(present("wang", environment(me))))
                     return notify_fail("������ס��˵���������Ǳ����صأ�ֻ�и������ż����������Ͳ��ܽ�ȥ��\n" + RANK_D->query_rude(me) +"�㻹�ǻ�ȥ�ɡ�\n");
           }
        }
        return ::valid_leave(me, dir);
}

