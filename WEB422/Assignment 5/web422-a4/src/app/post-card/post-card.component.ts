import { Component, OnInit, Input } from '@angular/core';
import { BlogPost } from '../BlogPost';

@Component({
  selector: 'app-post-card',
  templateUrl: './post-card.component.html',
  styleUrls: ['./post-card.component.css']
})

export class PostCardComponent implements OnInit {

  @Input() post: BlogPost;
 
  constructor() {
    console.log(this.post);
   }

  ngOnInit(): void {
    console.log(this.post);
  }


}
