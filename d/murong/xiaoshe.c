// /u/beyond/mr/xiaoshe.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short", HIY"С��"NOR);
         set("long",
"��䷿��С������, ��Ϊ���š�С���Ҷ���д�š�"HIY"����"NOR"�����ֱ���,\n"
"����Ϊ������Զ����С��¶��һ���ݽǡ��������߸���һ��С����֪ͨ�����\n"
);
         set("exits", ([
             "east" : __DIR__"xiaojing3",
"north" : __DIR__"xiaodao",
             "west" : __DIR__"xiaojing1",
]));
         set("objects",([
             __DIR__"npc/bao" : 1,          
]));
             setup();
          // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    object *inv;
       mapping myfam;
    int i;
               
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "����Ľ��" ) && dir == "west") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("bao butong", environment(me))))
                    return notify_fail("����ͬ��ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�Ϊ�˱�ʾ"
                        "�Թ���Ľ�ݵľ���������±���������Ľ�ݡ�\n");
                
    }
    return ::valid_leave(me, dir);
}

