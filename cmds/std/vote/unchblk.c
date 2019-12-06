// vote unchblk
#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  string channel;
  string *juror, my_id;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

/*
  if(victim->query("chblk_on") || victim->query("chblk_chat"))
  {
  	channel = "��̸";
  } else if (victim->query("chblk_rumor")) 
  {
  	channel = "ҥ��";
  } else 
  	return notify_fail(victim->name()+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");
  

*/
        channel = "����";
  if(time() - victim->query("chblk_channel/chat") >= 3600 )
          return notify_fail(victim->name()+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");
  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

//  vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
  vv = (int) ("/cmds/std/vote")->valid_voters(me);
  if( vv < 50 ) vv = vv/3;
  else vv = vv/4;
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 4) df = 4 - vc;
  
  my_name = me->name();
  if (me == victim) v_name = "�Լ�";
  	else  v_name = victim->name();

  if (df>1)
  {
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
    
	victim->apply_condition("vote_clear", 10);
			        
  } else 
  {
  	if (me != victim)
  	{
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name+"��"+channel+"Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name+"��"+channel+"Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	} else 
	{
	shout( HIG "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	}		
	
	victim->apply_condition("vote_clear", -10);
	if (victim->query("chblk_on")) victim->delete("chblk_on");
//        if (victim->query("chblk_rumor")) victim->delete("chblk_rumor");
        if (victim->query("chblk_channel/chat")) victim->delete("chblk_channel/chat");
//        if (victim->query("chblk_chat")) victim->delete("chblk_chat");
  } 
  
  return 1;
}

