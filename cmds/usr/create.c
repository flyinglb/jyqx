            // create.c ����Խ�����
// byp@jyqxz 2000/09/29

#include <ansi.h>
inherit F_CLEAN_UP;

string filter_str(string str);
string conversion_color(string str);

int main(object me, string arg)
{
        string family_name, str;

        if(!wizardp(me))
                return notify_fail("�������������ʱ������ҿ��š�\n");

        if( !arg ) return notify_fail("��Ҫ����ʲô���ɣ�\n");
        
        //if( arg == me->query("family/family_name") )
                //return notify_fail("���Լ�������"+ me->query("family/family_name") +"��ô��\n");
        
        if( !undefinedp(me->query("family/family_name")) || !me->query("chushi") )
                return notify_fail("�㻹û��ʦ���������Ż����������ʦ�Ĵ��ﰡ��\n");
        
        if(me->query("combat_exp") < 8000000 )
                return notify_fail("��ʵս���鲻����ν̵����ӣ�\n");
        
        if(me->query("weiwang") < 500 )
                return notify_fail("��û�е�������η��ڣ�\n");
        
        if(me->query("score") < 500)
                return notify_fail("���Լ���ûʲô��ʶ������ô����������£�\n");
        
        if(me->query("meili") < 100)
                return notify_fail("�������������ô���쵼���ˣ�\n");
        
        str = filter_str(arg);

        if( strlen(str) > 10 )
                return notify_fail("��������������̫���ˣ����������ĺ�����ġ�\n");
        
        family_name = conversion_color(arg);
        
        me->create_family(family_name, 1, "��ɽ��ʦ");
        
        //��¼�Դ�������Ϣ
        /*log_file("player_familys",
        sprintf("family %s %s %s\n",me->name() , family_name, ctime(time())));
        */
        CHANNEL_D->do_channel(me, "rumor",
                "��˵"+ me->name() +"�����˸� "+ family_name + HIR + " ������������Ҫ���Ƿ��ˣ�\n");
        return 1;
}

string filter_str(string str)
{
        str = replace_string(str, "$BLK$", "");
        str = replace_string(str, "$RED$", "");
        str = replace_string(str, "$GRN$", "");
        str = replace_string(str, "$YEL$", "");
        str = replace_string(str, "$BLU$", "");
        str = replace_string(str, "$MAG$", "");
        str = replace_string(str, "$CYN$", "");
        str = replace_string(str, "$WHT$", "");
        str = replace_string(str, "$HIR$", "");
        str = replace_string(str, "$HIG$", "");
        str = replace_string(str, "$HIY$", "");
        str = replace_string(str, "$HIB$", "");
        str = replace_string(str, "$HIM$", "");
        str = replace_string(str, "$HIC$", "");
        str = replace_string(str, "$HIW$", "");
        str = replace_string(str, "$NOR$", "");
        str = replace_string(str, "$HBRED$", "");
        str = replace_string(str, "$HBGRN$", "");
        str = replace_string(str, "$HBYEL$", "");
        str = replace_string(str, "$HBBLU$", "");
        str = replace_string(str, "$HBMAG$", "");
        str = replace_string(str, "$HBCYN$", "");
        str = replace_string(str, "$HBWHT$", "");
        str = replace_string(str, "$BLINK$", "");
        return str;
}

string conversion_color(string str)
{
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);
        str = replace_string(str, "$HBRED$", HBRED);
        str = replace_string(str, "$HBGRN$", HBGRN);
        str = replace_string(str, "$HBYEL$", HBYEL);
        str = replace_string(str, "$HBBLU$", HBBLU);
        str = replace_string(str, "$HBMAG$", HBMAG);
        str = replace_string(str, "$HBCYN$", HBCYN);
        str = replace_string(str, "$HBWHT$", HBWHT);
//      str = replace_string(str, "$BLINK$", BLINK);
        return str + NOR;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : create <��������>
 
���ָ��������㽨��һ�������Լ������ɡ�(������)
 
���������ȱ���Ҫ��ʦ
      ʵս���������� 8000000 (8M)
      ��������������� 500 
      ��������������� 500
      ��    ��������� 100     

 *ע ������������������
     ���ڲ��ŵ�������ʦ��Ȩɾ��
 ������һ������ʱ�������뽨�����ɷ���(��������)
     �����������Ȩ��������ʦ��

������apprentice(bai) recruit(shou)    expell(kaichu)
          teach(jiao)     learn(xue)
          practice(lian)  research(yanjiu)
HELP
    );
    return 1;
}
