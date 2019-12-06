//
// checkout.c
//
// Created :  96-08-15  09:20PM   Falcon
//

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "blade":        "����",
        "stick":        "����",
        "staff":        "�ȷ�",
        "throwing":     "����",
	"iron-cloth": 	"Ӳ��",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "magic":        "����",
        "spells":       "����",
        "move":         "�ж�",
        "array":        "��",
	"whip":     	"�޷�",
]);

int main(object me, string arg)
{
	object player;
        mapping map;
        string *skill;
        int i, modify;

        if ( arg )
	{
         	player = present( arg, environment( me ) );
		if ( !player )
			player = find_player( arg );
		if ( !player )
			player = find_living( arg );
		if ( !player )
			return notify_fail( "����鿴˭��״̬? \n" );	
		map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

                skill = keys(valid_types);
                write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" : 
to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }
	else
	{
        	return notify_fail( "���뿴˭��״̬��? \n" );
	}
}
