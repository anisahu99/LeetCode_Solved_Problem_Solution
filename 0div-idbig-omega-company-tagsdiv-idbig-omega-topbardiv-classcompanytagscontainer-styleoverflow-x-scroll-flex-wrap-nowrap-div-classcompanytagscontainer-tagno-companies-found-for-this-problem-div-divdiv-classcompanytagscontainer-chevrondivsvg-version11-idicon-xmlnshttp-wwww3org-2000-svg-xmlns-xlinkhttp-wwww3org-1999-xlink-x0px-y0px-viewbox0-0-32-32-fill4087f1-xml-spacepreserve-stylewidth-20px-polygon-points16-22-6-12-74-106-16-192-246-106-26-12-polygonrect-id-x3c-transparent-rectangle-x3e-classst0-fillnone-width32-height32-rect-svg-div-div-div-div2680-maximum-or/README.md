<h2><a href="https://leetcode.com/problems/maximum-or/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2680. Maximum OR</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>. In an operation, you can choose an element and multiply it by <code>2</code>.</p>

<p>Return <em>the maximum possible value of </em><code>nums[0] | nums[1] | ... | nums[n - 1]</code> <em>that can be obtained after applying the operation on nums at most </em><code>k</code><em> times</em>.</p>

<p>Note that <code>a | b</code> denotes the <strong>bitwise or</strong> between two integers <code>a</code> and <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [12,9], k = 1
<strong>Output:</strong> 30
<strong>Explanation:</strong> If we apply the operation to index 1, our new array nums will be equal to [12,18]. Thus, we return the bitwise or of 12 and 18, which is 30.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [8,1,2], k = 2
<strong>Output:</strong> 35
<strong>Explanation:</strong> If we apply the operation twice on index 0, we yield a new array of [32,1,2]. Thus, we return 32|1|2 = 35.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 15</code></li>
</ul>
</div>