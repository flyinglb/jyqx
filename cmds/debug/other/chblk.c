// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
    
    if (sscanf(arg, "%s %s", who, ch_name) != 2)
    {
        ch_name = "";
        if (sscanf(arg, "%s", who) != 1)
        {
        return  notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
        }   
    }

	if (who == "rumor")
	{
		CHANNEL_D->set_block("rumor", 1);
		CHANNEL_D->do_channel(me, "sys", "ҥ��Ƶ���ر��ˡ�\n");
		return 1;
	}
	
	if (who == "chat")
	{
		CHANNEL_D->set_block("chat", 1);
		CHANNEL_D->do_channel(me, "sys", "����Ƶ���ر��ˡ�\n");
//		write("�������Ƶ���ر��ˡ�\n");
		return 1;
	}
	
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("����˲��ڣ�\n");
	if (wizardp(ob)) return notify_fail("���ܹر���ʦ��Ƶ����\n");
	
	if (ch_name == "" || ch_name == " ") 
	{
		if ( ob->query("chblk_on") || ob->query("chblk_rumor") )
		{
			tell_object(me, (string)ob->query("name")+"��ҥ��Ƶ���ǹرյġ�\n");
		}
		if ( ob->query("chblk_on") || ob->query("chblk_chat") )
		{
			tell_object(me, (string)ob->query("name")+"������Ƶ���ǹرյġ�\n");
		}
		if (!(ob->query("chblk_on")||ob->query("chblk_rumor")||ob->query("chblk_chat"))) 
		{
			tell_object(me, (string)ob->query("name")+"û�б��رյ�Ƶ����\n");
		}
	} else if (ch_name == "rumor")	
	{
		if ( ob->query("chblk_on") || ob->query("chblk_rumor") )
		{
			tell_object(me, (string)ob->query("name")+"��ҥ��Ƶ���Ѿ��ǹرյ��ˡ�\n");
		} else 
		{
			if ( ob->query("chblk_chat") )
			{
				ob->delete("chblk_chat");
				ob->set("chblk_on", 1);
			} else {
				ob->set("chblk_rumor", 1);
			}
			tell_object(me, (string)ob->query("name")+"��ҥ��Ƶ�����ر��ˡ�\n");
	    }	
	} else if (ch_name == "all")
	{
		if ( ob->query("chblk_on") )
		{
			tell_object(me, (string)ob->query("name")+"��Ƶ���Ѿ��ǹرյ��ˡ�\n");
		} else 
		{
			ob->set("chblk_on", 1);
			ob->delete("chblk_rumor");
			ob->delete("chblk_chat");
			tell_object(me, (string)ob->query("name")+"��Ƶ�����ر��ˡ�\n");
		}
	} else if (ch_name == "chat")
	{
		if ( ob->query("chblk_on") || ob->query("chblk_chat") )
		{
			tell_object(me, (string)ob->query("name")+"������Ƶ���Ѿ��ǹرյ��ˡ�\n");
		} else 
		{
			if ( ob->query("chblk_rumor") )
			{
				ob->delete("chblk_rumor");
				ob->set("chblk_on", 1);
			} else {
				ob->set("chblk_chat", 1);
			}
			tell_object(me, (string)ob->query("name")+"������Ƶ�����ر��ˡ�\n");
		}
	} else 
	{
	return notify_fail("<Syntax>: chblk <player id> <channel name>\n");
	}
		
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : chblk <ĳ��> <Ƶ����>

������ر�ĳ�˵�ĳ��Ƶ����
<Ƶ����>��������rumor��chat��all��������ṩƵ����������ʾĳ�˵�ǰ��Ƶ��״̬�� 

���ң�
chblk rumor ���ر�ҥ��Ƶ����
chblk chat ���ر�����Ƶ����

HELP
    );
    return 1;
}
