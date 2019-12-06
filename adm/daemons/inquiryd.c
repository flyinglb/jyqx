// inquiryd.c
// Created by Annihilator@ES2 (01-19-95)
// Modified by Xiang for XKX (12/20/95)

// This function handles the default inquiry between ppls and npcs to
// make npc more talktive. This is the '<me> ask <ob> about <topic>'
// case.

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
			message_vision( CYN "$N��$n�ʵ�������" + RANK_D->query_respect(ob)
				+ "���մ�����\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "��" + RANK_D->query_self(me) + "����է������֪������Щʲ��������飿\n" NOR,
				me, ob);
			return 1;
		case "rumors":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����֪�����û����˵ʲô��Ϣ��\n" NOR, me, ob);
			return 1;
		case "marry":
			message_vision(CYN "$NЦ�Ǻǵ���$n�ʵ���������λ"+RANK_D->query_respect(ob)
						+"�Ƿ���䣿\n" NOR,me,ob);
		default:
			return 0;
	}
}
