// zhenyue.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�������бڶ������ı����ֱ��գ���ɫ��������ǰ����(jing)����
����������ǧҶ���������������Ϊƽ̹���ϡ���ɽ���οͶ��ڴ�������
Ϣ�ټ���ǰ�С������м����ª�����磬���Ƕ�����ճ��ߣ�����ͷ��
ЪϢ�ڴˡ�
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "northdown"  : __DIR__"jinsuo",
            "eastup"     : __DIR__"yunu",
            "southwest"  : __DIR__"lianpath1",
        ]));
        set("objects", ([
            __DIR__"npc/gao-genming" : 1,
        ]));
        set("item_desc", ([
            "jing" : "����ˮɫ��͸�����ֿ�����\n",
        ]));

//        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        set("resource/water", 1);

        setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir != "northdown" )
	{
                if(me->query("family/family_name") !="��ɽ��" && !wizardp(me))
		{
                         if(me->query("combat_exp") >= 5000)
			{
				if(present("gao genming", environment(me)) && living(present("gao genming", environment(me))))
				{
					return notify_fail(
"�߸����ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
				}
				else
					return ::valid_leave(me, dir);
			}
			else
				return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}
