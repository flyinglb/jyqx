//unchblk.c Ƶ������
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string verb;
        int times = time();
        if(!wizardp(me))
                return notify_fail("�����ʲô��\n");
                
        if( !arg || sscanf(arg, "%s %s", arg, verb)!=2 )
                return notify_fail("ָ���ʽ��chblk <id> [<channels> | all]\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("û�������ҡ�\n");
                
        if(who->query("chblk_on")) who->delete("chblk_on");
        who->set("chblk_channel/"+verb, times);
        CHANNEL_D->do_channel(this_object(),
		"rumor","��������ó�һ�Ź�Ƥ��ҩ����С��¯��ϸϸ�������Ժ󣬡�ž������ס��"+who->name()+"����͡�\n");
        write(who->name()+"("+who->query("id")+")��"+verb+"Ƶ�������ơ�\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+me->query("id")+") ��"+who->name()+"("+who->query("id")+")��"+verb+"Ƶ�����ơ�\n");
        return 1;
}
