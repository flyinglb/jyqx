// channel block command..
// Modified by Marz, 04/18/96

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
		return	notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}		
	}

    if (who == "rumor")
    {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "ҥ��Ƶ���������\n");
        return 1;
    }
	
    if (who == "chat")
    {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "����Ƶ���������\n");
        return 1;
    }
	
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("����˲��ڣ�\n");
	
	if (ch_name == ""||ch_name == " "||ch_name == "all")
	{		
		if ((int)ob->query("chblk_on"))
			ob->delete("chblk_on");
		if ((int)ob->query("chblk_rumor"))
			ob->delete("chblk_rumor");
		if ((int)ob->query("chblk_chat"))
			ob->delete("chblk_chat");
		tell_object(me, (string)ob->query("name")+"��Ƶ�������ˡ�\n");
	} else if (ch_name == "rumor")
	{
		if ((int)ob->query("chblk_on"))
		{
			ob->delete("chblk_on");
			ob->set("chblk_chat", 1);
		}
		
		if ((int)ob->query("chblk_channel/rumor"))
			ob->delete("chblk_channel/rumor");
			
		tell_object(me, (string)ob->query("name")+"��ҥ��Ƶ�������ˡ�\n");
	} else if (ch_name == "chat")
	{
		if ((int)ob->query("chblk_on"))
		{
			ob->delete("chblk_on");
			ob->set("chblk_rumor", 1);
		}
		
		if ((int)ob->query("chblk_channel/chat"))
			ob->delete("chblk_channel/chat");
			
		tell_object(me, (string)ob->query("name")+"������Ƶ�������ˡ�\n");
	} else 
	{
		return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
	}		
	
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : unchblk <ĳ��> <Ƶ����>

�������ĳ�˵�Ƶ�������û��Ƶ�����ʹ����кϷ�Ƶ����
<ĳ��>��Ҳ������Ƶ������
<Ƶ����> ������rumor �� chat 

HELP
    );
    return 1;
}
